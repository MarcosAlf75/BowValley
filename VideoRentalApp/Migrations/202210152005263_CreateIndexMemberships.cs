namespace VideoRentalApp.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class CreateIndexMemberships : DbMigration
    {
        public override void Up()
        {
            //AddColumn("dbo.Customers", "DateOfBirth", c => c.DateTime(nullable: false));
            //CreateIndex("dbo.Customers", "MembershipId");
        }
        
        public override void Down()
        {
            //DropColumn("dbo.Customers", "DateOfBirth");
        }
    }
}
