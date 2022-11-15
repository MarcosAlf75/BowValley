namespace VideoRentalApp.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class UpdateNameMembership : DbMigration
    {
        public override void Up()
        {
            AddColumn("dbo.Memberships", "Name", c => c.String());
        }
        
        public override void Down()
        {
            DropColumn("dbo.Memberships", "Name");
        }
    }
}
