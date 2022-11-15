namespace VideoRentalApp.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class Restart02 : DbMigration
    {
        public override void Up()
        {
            RenameColumn(table: "dbo.Movies", name: "MovieTypes_Id", newName: "MovieT_Id");
            RenameIndex(table: "dbo.Movies", name: "IX_MovieTypes_Id", newName: "IX_MovieT_Id");
        }
        
        public override void Down()
        {
            RenameIndex(table: "dbo.Movies", name: "IX_MovieT_Id", newName: "IX_MovieTypes_Id1");
            RenameColumn(table: "dbo.Movies", name: "MovieT_Id", newName: "MovieTypes_Id1");
        }
    }
}
