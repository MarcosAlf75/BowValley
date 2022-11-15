namespace VideoRentalApp.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class PopulateMembership : DbMigration
    {
        public override void Up()
        {
            Sql("set Identity_insert Memberships ON");

            Sql("insert into memberships(Id, MonthlyDuration, Fee, DiscountRate) values (1,0,0,0)");
            Sql("insert into memberships(Id, MonthlyDuration, Fee, DiscountRate) values (2,1,10,10)");
            Sql("insert into memberships(Id, MonthlyDuration, Fee, DiscountRate) values (3,6,50,20)");
            Sql("insert into memberships(Id, MonthlyDuration, Fee, DiscountRate) values (4,12,100,40)");

            Sql("set Identity_insert Memberships OFF");
        }
    }
}
