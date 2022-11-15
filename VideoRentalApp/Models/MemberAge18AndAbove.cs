using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Runtime.Remoting.Messaging;
using System.Web;

namespace VideoRentalApp.Models
{
    public class MemberAge18AndAbove : ValidationAttribute
    {
        protected override ValidationResult IsValid(object value, ValidationContext validationContext)
        {
            var customer = (Customer)validationContext.ObjectInstance;
            if (customer.MembershipId == Membership.NotSelected || customer.MembershipId == Membership.PayAsYouGo)
            {
                return ValidationResult.Success;
            }
            if (customer.DateOfBirth == null)
            {
                return new ValidationResult("Please enter Birth Day");
            }
            var age = DateTime.Today.Year - customer.DateOfBirth.Value.Year;
            return age > 18 ? ValidationResult.Success : new ValidationResult("Customer must be 18 for regular membership!");
        }
    }
}