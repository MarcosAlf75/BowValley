namespace VideoRentalApp.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class UpdateTAbles : DbMigration
    {
        public override void Up()
        {
            DropForeignKey("dbo.MovieTypes", "Movie_Id", "dbo.Movies");
            DropIndex("dbo.MovieTypes", new[] { "Movie_Id" });
            AddColumn("dbo.Movies", "MovieID", c => c.Int(nullable: false));
            AddColumn("dbo.Movies", "MovieTypes_Id", c => c.Int());
            CreateIndex("dbo.Movies", "MovieTypes_Id");
            AddForeignKey("dbo.Movies", "MovieTypes_Id", "dbo.MovieTypes", "Id");
            DropColumn("dbo.MovieTypes", "Movie_Id");
        }
        
        public override void Down()
        {
            AddColumn("dbo.MovieTypes", "Movie_Id", c => c.Int());
            DropForeignKey("dbo.Movies", "MovieTypes_Id", "dbo.MovieTypes");
            DropIndex("dbo.Movies", new[] { "MovieTypes_Id" });
            DropColumn("dbo.Movies", "MovieTypes_Id");
            DropColumn("dbo.Movies", "MovieID");
            CreateIndex("dbo.MovieTypes", "Movie_Id");
            AddForeignKey("dbo.MovieTypes", "Movie_Id", "dbo.Movies", "Id");
        }
    }
}
