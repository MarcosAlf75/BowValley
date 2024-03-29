﻿namespace VideoRentalApp.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class UpdateName : DbMigration
    {
        public override void Up()
        {
            Sql("UPDATE Memberships SET Name = 'Pay as You Go' WHERE Id = 1");
            Sql("UPDATE Memberships SET Name = 'Monthly' WHERE Id = 2");
            Sql("UPDATE Memberships SET Name = 'Six Monthly' WHERE Id = 3");
            Sql("UPDATE Memberships SET Name = 'Yearly' WHERE Id = 4");
        }

        public override void Down()
        {
        }
    }
}
