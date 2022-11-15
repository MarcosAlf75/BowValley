namespace VideoRentalApp.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class PopulateMAndMT : DbMigration
    {
        public override void Up()
        {
            Sql("set Identity_insert movietypes ON");

            Sql("insert into movietypes(Id, TypeDescription) values(1,'Action')");
            Sql("insert into movietypes(Id, TypeDescription) values(2,'Comedy')");
            Sql("insert into movietypes(Id, TypeDescription) values(3,'Animation')");
            Sql("insert into movietypes(Id, TypeDescription) values(4,'Fiction')");
            Sql("insert into movietypes(Id, TypeDescription) values(5,'Romance')");
            Sql("insert into movietypes(Id, TypeDescription) values(6,'Adventure')");
            Sql("insert into movietypes(Id, TypeDescription) values(7,'Westerm')");
            Sql("insert into movietypes(Id, TypeDescription) values(8,'Horror')");

            Sql("set Identity_insert movietypes OFF");
        }
        
        public override void Down()
        {
        }
    }
}
