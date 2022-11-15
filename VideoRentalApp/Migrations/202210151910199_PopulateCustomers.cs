namespace VideoRentalApp.Migrations
{
    using System;
    using System.ComponentModel.DataAnnotations;
    using System.Data.Entity.Migrations;
    
    public partial class PopulateCustomers : DbMigration
    {
        public override void Up()
        {

            Sql("set Identity_insert customers ON");

            Sql("insert into customers(Id, Name, DateOfBirth, isSubscribed, MembershipId) values (1, 'John Hamilton','19950505','true', 1)");
            Sql("insert into customers(Id, Name, isSubscribed, MembershipId) values (2,'Bill Moore','true', 2)");
            Sql("insert into customers(Id, Name, DateOfBirth, isSubscribed, MembershipId) values (3,'JRossy Taylor','20011002','true', 4)");

    }
        
        public override void Down()
        {
        }
    }
}
