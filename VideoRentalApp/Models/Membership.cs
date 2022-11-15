using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;

namespace VideoRentalApp.Models
{
    public class Membership
    {
        public static readonly byte NotSelected = 0;
        public static readonly byte PayAsYouGo = 1;

        public int Id { get; set; }
        public string Name { get; set; } 
        public Byte MonthlyDuration { get; set; }
        public short Fee { get; set; }
        public Byte DiscountRate { get; set; }
    }
}