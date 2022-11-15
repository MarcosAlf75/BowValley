namespace VideoRentalApp.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class AddTypeIDMovie : DbMigration
    {
        public override void Up()
        {
            AddColumn("dbo.Movies", "MovieTypes_Id", c => c.Int());
        }
        
        public override void Down()
        {
            DropColumn("dbo.Movies", "MovieTypes_Id");
        }
    }
}
