namespace VideoRentalApp.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class CreateMembership : DbMigration
    {
        public override void Up()
        {
            CreateTable(
                "dbo.Memberships",
                c => new
                    {
                        Id = c.Int(nullable: false, identity: true),
                        MonthlyDuration = c.Byte(nullable: false),
                        Fee = c.Short(nullable: false),
                        DiscountRate = c.Byte(nullable: false),
                    })
                .PrimaryKey(t => t.Id);
            
            //AddColumn("dbo.Customers", "isSubscribed", c => c.Boolean(nullable: false));
            //AddColumn("dbo.Customers", "MembershipId", c => c.Int(nullable: false));
            //AlterColumn("dbo.Customers", "Name", c => c.String(nullable: false, maxLength: 100));
            CreateIndex("dbo.Customers", "MembershipId");
            AddForeignKey("dbo.Customers", "MembershipId", "dbo.Memberships", "Id", cascadeDelete: true);
        }
        
        public override void Down()
        {
            DropForeignKey("dbo.Customers", "MembershipId", "dbo.Memberships");
            DropIndex("dbo.Customers", new[] { "MembershipId" });
            AlterColumn("dbo.Customers", "Name", c => c.String());
            DropColumn("dbo.Customers", "MembershipId");
            DropColumn("dbo.Customers", "isSubscribed");
            DropTable("dbo.Memberships");
        }
    }
}
