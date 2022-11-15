namespace VideoRentalApp.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class FixMovieTable02 : DbMigration
    {
        public override void Up()
        {
            //DropForeignKey("dbo.Movies", "MovieType_Id", "dbo.MovieTypes");
            //DropIndex("dbo.Movies", new[] { "MovieType_Id" });
            //DropTable("dbo.Movies");
            //DropTable("dbo.MovieTypes");
        }
        
        public override void Down()
        {
            CreateTable(
                "dbo.MovieTypes",
                c => new
                    {
                        Id = c.Int(nullable: false, identity: true),
                        TypeDescription = c.String(),
                    })
                .PrimaryKey(t => t.Id);
            
            CreateTable(
                "dbo.Movies",
                c => new
                    {
                        Id = c.Int(nullable: false, identity: true),
                        Name = c.String(),
                        ReleaseDate = c.DateTime(nullable: false),
                        DayAdded = c.DateTime(nullable: false),
                        NumberInStock = c.Int(nullable: false),
                        MovieTypes_Id = c.Int(nullable: false),
                        MovieType_Id = c.Int(),
                    })
                .PrimaryKey(t => t.Id);
            
            CreateIndex("dbo.Movies", "MovieType_Id");
            AddForeignKey("dbo.Movies", "MovieType_Id", "dbo.MovieTypes", "Id");
        }
    }
}
