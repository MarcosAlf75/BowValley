namespace VideoRentalApp.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class FixMovieTable01 : DbMigration
    {
        public override void Up()
        {
            RenameColumn(table: "dbo.Movies", name: "MovieT_Id", newName: "MovieType_Id");
            RenameIndex(table: "dbo.Movies", name: "IX_MovieT_Id", newName: "IX_MovieType_Id");
            AlterColumn("dbo.Movies", "MovieTypes_Id", c => c.Int(nullable: false));
        }
        
        public override void Down()
        {
            AlterColumn("dbo.Movies", "MovieTypes_Id", c => c.Int());
            RenameIndex(table: "dbo.Movies", name: "IX_MovieType_Id", newName: "IX_MovieT_Id");
            RenameColumn(table: "dbo.Movies", name: "MovieType_Id", newName: "MovieT_Id");
        }
    }
}
