namespace VideoRentalApp.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class FixMovieTable06 : DbMigration
    {
        public override void Up()
        {
            Sql("set Identity_insert movietypes ON");

            Sql("insert into movietypes(Id, TypeDescription) values(1,'Action')");
            Sql("insert into movietypes(Id, TypeDescription) values(2,'Comedy')");
            Sql("insert into movietypes(Id, TypeDescription) values(3,'Animation')");
            Sql("insert into movietypes(Id, TypeDescription) values(4,'Fiction')");
            Sql("insert into movietypes(Id, TypeDescription) values(5,'Romance')");
            Sql("insert into movietypes(Id, TypeDescription) values(6,'Adventure')");
            Sql("insert into movietypes(Id, TypeDescription) values(7,'Western')");
            Sql("insert into movietypes(Id, TypeDescription) values(8,'Horror')");

            Sql("set Identity_insert movietypes OFF");

            Sql("set Identity_insert movies ON");

            Sql("insert into movies(Id, Name, ReleaseDate, DayAdded, NumberInStock, MovieTypeId) values(1, 'Harry Potter', '2001-05-25', '2015-12-22', 4, 4)");
            Sql("insert into movies(Id, Name, ReleaseDate, DayAdded, NumberInStock, MovieTypeId) values(2, 'Hangover', '2003-04-16', '2015-12-22', 2, 2)");
            Sql("insert into movies(Id, Name, ReleaseDate, DayAdded, NumberInStock, MovieTypeId) values(3, 'Die Hard', '1984-02-14', '2015-12-22', 14, 1)");
            Sql("insert into movies(Id, Name, ReleaseDate, DayAdded, NumberInStock, MovieTypeId) values(4, 'Terminator', '1988-05-30', '2015-12-22', 7, 1)");
            Sql("insert into movies(Id, Name, ReleaseDate, DayAdded, NumberInStock, MovieTypeId) values(5, 'Toy Story', '2011-11-13', '2015-12-22', 1, 3)");
            Sql("insert into movies(Id, Name, ReleaseDate, DayAdded, NumberInStock, MovieTypeId) values(7, 'The Titanic', '1995-06-19', '2015-12-22', 6, 5)");
            Sql("insert into movies(Id, Name, ReleaseDate, DayAdded, NumberInStock, MovieTypeId) values(8, 'Kong: Skull Island', '1996-01-05', '2015-12-22', 3, 6)");
            Sql("insert into movies(Id, Name, ReleaseDate, DayAdded, NumberInStock, MovieTypeId) values(9, '3:10 to Yuma', '2010-05-25', '2015-12-22', 2, 7)");
            Sql("insert into movies(Id, Name, ReleaseDate, DayAdded, NumberInStock, MovieTypeId) values(10, 'The Others', '2002-04-18', '2015-12-22', 5, 8)");

            Sql("set Identity_insert movies OFF");
        }
        
        public override void Down()
        {
        }
    }
}
