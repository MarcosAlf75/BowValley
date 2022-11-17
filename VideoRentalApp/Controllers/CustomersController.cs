using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using VideoRentalApp;
using VideoRentalApp.Models;
using System.Data.Entity;
using VideoRentalApp.ViewModels;
using Microsoft.Ajax.Utilities;
using System.Web.Security;

namespace VideoRentalApp.Controllers
{
    public class CustomersController : Controller
    {
        //GET: Customers
        private readonly ApplicationDbContext _context;
        public CustomersController()
        {
            _context = new ApplicationDbContext();
        }
        protected override void Dispose(bool disposing)
        {
            _context.Dispose();
        }
        [Authorize]
        public ViewResult Index()
        {
            var customers = _context.Customers.Include(c => c.Membership).ToList();

            if (User.IsInRole("CanManageCustomers"))
                return View("IndexAdmin", customers);

            return View("indexUser",customers);
        }

		[Authorize(Roles = Role.CanManageCustomers)]
		public ViewResult NewCustomer()
        {
            var membership = _context.Memberships.ToList();
            Customer customer = new Customer();

            var viewModel = new CustomerViewModels
            {
                Memberships = membership, Customer = customer
            };
            ViewBag.Message = "New Customer";
            return View("CustomerForm", viewModel);  //can not pass just one model, 
                                      //need to pass Customer model as well
        }

		[Authorize(Roles = Role.CanManageCustomers)]
		[HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Save(Customer customer)
        {
            //[Bind(Exclude = "Id")]                                  
            if (!ModelState.IsValid)
            {

                var viewModel = new CustomerViewModels
                {
                    Customer = customer,
                    Memberships = _context.Memberships.ToList()
                };

                return View("CustomerForm", viewModel);
            }

            if (customer.Id == 0)
                {
                _context.Customers.Add(customer);
            }
            else
            {
                var customerInDB = _context.Customers.Single(c => c.Id == customer.Id);
                customerInDB.Name = customer.Name;
                customerInDB.DateOfBirth = customer.DateOfBirth;
                customerInDB.MembershipId = customer.MembershipId;
                customerInDB.isSubscribed = customer.isSubscribed;
            }
            _context.SaveChanges();

			var customers = _context.Customers.Include(c => c.Membership).ToList();
            return View("IndexAdmin", customers);
        }
		[Authorize(Roles = Role.CanManageCustomers)]
		public ActionResult Edit(int Id)
        {
            var membership = _context.Memberships.ToList();
            var customer = _context.Customers.SingleOrDefault(c => c.Id == Id);
            if (customer == null) return HttpNotFound();
            var viewModel = new CustomerViewModels
            {
                Memberships = membership,
                Customer = customer
            };
            ViewBag.Message = "Edit Customer";
            return View("CustomerForm", viewModel); //this code is expecting a view named Edit View, However, we can reuse 
        }                           //our newcustomer view, renaming the ViewModel and View would be great!
                                    // rename: NewCustomerViewModel to CustomerViewModel
                                    // rename: newcustomer View to CustomerForm View
        [HttpPost]
        [ValidateAntiForgeryToken]
		[Authorize(Roles = Role.CanManageCustomers)]
		public ActionResult Delete(int? Id)
        {
            var customer = _context.Customers.SingleOrDefault(c => c.Id == Id);
            if (customer == null)
                return HttpNotFound();
            _context.Customers.Remove(customer);
            _context.SaveChanges();

            var customers = _context.Customers.Include(c => c.Membership).ToList();

            return View("IndexAdmin", customers);
        }
    }
}