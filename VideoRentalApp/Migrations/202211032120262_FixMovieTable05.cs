namespace VideoRentalApp.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class FixMovieTable05 : DbMigration
    {
        public override void Up()
        {
            DropForeignKey("dbo.Movies", "MovieType_Id", "dbo.MovieTypes");
            DropIndex("dbo.Movies", new[] { "MovieType_Id" });
            RenameColumn(table: "dbo.Movies", name: "MovieType_Id", newName: "MovieTypeId");
            AlterColumn("dbo.Movies", "MovieTypeId", c => c.Int(nullable: false));
            CreateIndex("dbo.Movies", "MovieTypeId");
            AddForeignKey("dbo.Movies", "MovieTypeId", "dbo.MovieTypes", "Id", cascadeDelete: true);
        }
        
        public override void Down()
        {
            DropForeignKey("dbo.Movies", "MovieTypeId", "dbo.MovieTypes");
            DropIndex("dbo.Movies", new[] { "MovieTypeId" });
            AlterColumn("dbo.Movies", "MovieTypeId", c => c.Int());
            RenameColumn(table: "dbo.Movies", name: "MovieTypeId", newName: "MovieType_Id");
            CreateIndex("dbo.Movies", "MovieType_Id");
            AddForeignKey("dbo.Movies", "MovieType_Id", "dbo.MovieTypes", "Id");
        }
    }
}
