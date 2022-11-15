namespace VideoRentalApp.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class FixMovieTable04 : DbMigration
    {
        public override void Up()
        {
            DropColumn("dbo.Movies", "MovieTypes_Id");
        }
        
        public override void Down()
        {
            AddColumn("dbo.Movies", "MovieTypes_Id", c => c.Int(nullable: false));
        }
    }
}
