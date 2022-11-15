using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using VideoRentalApp.Models;
using System.Data.Entity;
using VideoRentalApp.ViewModels;

namespace VideoRentalApp.Controllers
{
    public class MovieController : Controller
    {
        // GET: Movie
        private readonly ApplicationDbContext _context;
        public MovieController()
        {
            _context = new ApplicationDbContext();
        }
        protected override void Dispose(bool disposing)
        {
            _context.Dispose();
        }
        public ViewResult Index()
        {
            var movies = _context.Movies.Include(c => c.MovieType).ToList();
            return View(movies);
            //return null;
        }
        public ActionResult DetailsMovie(int id)
        {
            var movies = _context.Movies.Include(c => c.MovieType).SingleOrDefault(c => c.Id == id);
            if (movies == null)
            {
                return HttpNotFound();
            }
            return View(movies);
            //return null;
        }
        public ViewResult NewMovie()
        {
            var movietype = _context.MovieTypes.ToList();
            Movie movie = new Movie();

            var viewModel = new MovieViewModels
            {
                MovieTypes = movietype,
                Movie = movie
            };
            ViewBag.Message = "New Movie";
            return View("MovieForm", viewModel);
            //return null;
 
        }
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Save(Movie movie)
        {
            if (!ModelState.IsValid)
            {
                var viewModel = new MovieViewModels
                {
                    Movie = movie,
                    MovieTypes = _context.MovieTypes.ToList()
                };
                return View("MovieForm", viewModel);
            }
            if (movie.Id == 0)
            {
                _context.Movies.Add(movie);
            }
            else
            {
                var movieInDB = _context.Movies.Single(c => c.Id == movie.Id);
                movieInDB.Name = movie.Name;
                movieInDB.ReleaseDate = movie.ReleaseDate;
                movieInDB.DayAdded = movie.DayAdded;
                movieInDB.NumberInStock = movie.NumberInStock;
                movieInDB.MovieTypeId = movie.MovieTypeId;
            }
            _context.SaveChanges();
            return RedirectToAction("Index", "Movie");
            //return null;
        }
        public ActionResult Edit(int Id)
        {
            var movieType = _context.MovieTypes.ToList();
            var movie = _context.Movies.Single(c => c.Id == Id);
            if (movieType == null)
                return HttpNotFound();
            var viewModel = new MovieViewModels
            {
                MovieTypes = movieType,
                Movie = movie
            };
            ViewBag.Message = "Edit Customer";
            return View("MovieForm", viewModel);
            //return null ;
        }
        public ActionResult Delete(int Id)
        {
            var movie = _context.Movies.SingleOrDefault(c => c.Id == Id);
            if (movie == null)
                return HttpNotFound();
            _context.Movies.Remove(movie);
            _context.SaveChanges();

            var movies = _context.Movies.Include(c => c.MovieType).ToList();

            return View("Index", movies);
        }
    }
}