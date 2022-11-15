namespace VideoRentalApp.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class FixMovieTable03 : DbMigration
    {
        public override void Up()
        {
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
                .PrimaryKey(t => t.Id)
                .ForeignKey("dbo.MovieTypes", t => t.MovieType_Id)
                .Index(t => t.MovieType_Id);
            
            CreateTable(
                "dbo.MovieTypes",
                c => new
                    {
                        Id = c.Int(nullable: false, identity: true),
                        TypeDescription = c.String(),
                    })
                .PrimaryKey(t => t.Id);
            
        }
        
        public override void Down()
        {
            DropForeignKey("dbo.Movies", "MovieType_Id", "dbo.MovieTypes");
            DropIndex("dbo.Movies", new[] { "MovieType_Id" });
            DropTable("dbo.MovieTypes");
            DropTable("dbo.Movies");
        }
    }
}
