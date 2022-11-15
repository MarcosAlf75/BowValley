using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Security;
using VideoRentalApp.Models;
using Membership = VideoRentalApp.Models.Membership;

namespace VideoRentalApp.ViewModels
{
    public class CustomerViewModels
    {
        public IEnumerable<Membership> Memberships { get; set; }
        public Customer Customer { get; set; }
        public string CustomerViewModelTitlePage
        {
            get { return Customer.Id == 0 ? "New Customer" : "Edit Customer"; }
        }
        public string CustomerViewModelTitlePageDelete
        {
            get { return Customer.Id == 0 ? "There is no customer" : "Delete Customer"; }
        }
    }
}