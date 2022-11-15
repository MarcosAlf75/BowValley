using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using VideoRentalApp.Migrations;
using VideoRentalApp.Models;
using MovieType = VideoRentalApp.Models.MovieType;


namespace VideoRentalApp.ViewModels
{
    public class MovieViewModels
    {
        public IEnumerable<MovieType> MovieTypes { get; set; }
        public Movie Movie { get; set; }
        public string MovieViewModelTitlePage
        {
            get { return Movie.Id == 0 ? "New Movie" : "Edit Movie"; }
        }
    }
}