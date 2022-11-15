namespace VideoRentalApp.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class Restart : DbMigration
    {
        public override void Up()
        {
            DropForeignKey("dbo.Movies", "MovieTypes_Id", "dbo.MovieTypes");
            DropIndex("dbo.Movies", new[] { "MovieTypes_Id" });
            AddColumn("dbo.Movies", "MovieTypes_Id1", c => c.Int());
            AlterColumn("dbo.Movies", "MovieTypes_Id", c => c.Int(nullable: false));
            CreateIndex("dbo.Movies", "MovieTypes_Id1");
            AddForeignKey("dbo.Movies", "MovieTypes_Id1", "dbo.MovieTypes", "Id");
            DropColumn("dbo.Movies", "MovieID");
        }
        
        public override void Down()
        {
            AddColumn("dbo.Movies", "MovieID", c => c.Int(nullable: false));
            DropForeignKey("dbo.Movies", "MovieTypes_Id1", "dbo.MovieTypes");
            DropIndex("dbo.Movies", new[] { "MovieTypes_Id1" });
            AlterColumn("dbo.Movies", "MovieTypes_Id", c => c.Int());
            DropColumn("dbo.Movies", "MovieTypes_Id1");
            CreateIndex("dbo.Movies", "MovieTypes_Id");
            AddForeignKey("dbo.Movies", "MovieTypes_Id", "dbo.MovieTypes", "Id");
        }
    }
}
