namespace VideoRentalApp.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class dropcolumn : DbMigration
    {
        public override void Up()
        {
            DropColumn("dbo.Movies", "MovieID");
        }
        
        public override void Down()
        {
        }
    }
}
