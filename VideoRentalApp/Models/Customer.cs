using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;
using System.Web.Security;

namespace VideoRentalApp.Models
{    public class Customer
    {
        public int Id { get; set; }
        [Required(ErrorMessage = "Please enter Customer Name!")]
        [StringLength(100)]
        public String Name { get; set; }
        [Display(Name="Day of Birth")]
        [MemberAge18AndAbove]
        public DateTime? DateOfBirth { get; set; }
        public bool isSubscribed { get; set; }
        public Membership Membership { get; set; }
        [Display(Name ="Membership Name")]
        [Required(ErrorMessage = "Please enter Membership Name")]
        public int MembershipId { get; set; }
    }
}