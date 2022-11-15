using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Web;
using System.Xml.Linq;

namespace VideoRentalApp.Models
{
    public class Movie
    {
        public int Id { get; set; }

        [Required(ErrorMessage = "Name field is required")]
        [MaxLength(100)]
        public string Name { get; set; }
        [Display(Name = "Release Date")]
        [DataType(DataType.Date)]
        [Required(AllowEmptyStrings = false, ErrorMessage = "Release Date field is required")]
        public DateTime? ReleaseDate { get; set; }
        [Display(Name ="Day Added")]
        [DataType(DataType.Date)]
        public DateTime? DayAdded { get; set; }
        [Required]
        [Range(1, 20, ErrorMessage = "In Stock field is required")]
        [Display(Name ="In Stock")]
        public int NumberInStock { get; set; }
        [Display(Name = "Gender")]
        public MovieType MovieType { get; set; }
        public int MovieTypeId { get; set; }
    }
}
