#!/usr/bin/php
<?PHP
if (!isset($argc))
	exit;
include ("product_table_handle.php");


$user['id'] = "admin";
$user['right'] = "admin";
$table_user['admin'] = $user;
if (!file_exists("private"))
	mkdir('private', 0777);
serialize_put_content('private/user', $table_user);
$data[] = array('login' => "admin", 'passwd' => hash("whirlpool", "admin"));
serialize_put_content('private/passwd', $data);

category_add_entry("All Products");
category_add_entry("Red-Rabbit");
category_add_entry("Bedeux");
category_add_entry("Blackkross");
category_add_entry("Bustin");
category_add_entry("Kryptonics");
category_add_entry("Venture");
category_add_entry("Board");
category_add_entry("Weels");
category_add_entry("Truck");

product_add_entry("Bedeux deck 00", array("All Products", "Bedeux", "Board"), "img/deck/Bedeux_deck00.jpg", "149.99");
product_add_entry("Bedeux deck 01", array("All Products", "Bedeux", "Board"), "img/deck/Bedeux_deck01.jpg", "99.99");
product_add_entry("Bedeux deck 02", array("All Products", "Bedeux", "Board"), "img/deck/Bedeux_deck02.jpg", "129.99");

product_add_entry("Blackkross deck 00", array("All Products", "Blackkross", "Board"), "img/deck/Blackkross_deck00.jpg", "169.99");
product_add_entry("Blackkross deck 01", array("All Products", "Blackkross", "Board"), "img/deck/Blackkross_deck01.jpg", "129.99");
product_add_entry("Blackkross deck 02", array("All Products", "Blackkross", "Board"), "img/deck/Blackkross_deck02.jpg", "99.99");

product_add_entry("Bustin deck 00", array("All Products", "Bustin", "Board"), "img/deck/Bustin_deck00.jpg", "79.99");
product_add_entry("Bustin deck 01", array("All Products", "Bustin", "Board"), "img/deck/Bustin_deck01.jpg", "129.99");
product_add_entry("Bustin deck 02", array("All Products", "Bustin", "Board"), "img/deck/Bustin_deck02.jpg", "89.99");

product_add_entry("Venture truck 00", array("All Products", "Venture", "Truck"), "img/truck/Venture_truck00.jpg", "5.99");
product_add_entry("Venture truck 01", array("All Products", "Venture", "Truck"), "img/truck/Venture_truck01.jpg", "5.99");
product_add_entry("Venture truck 02", array("All Products", "Venture", "Truck"), "img/truck/Venture_truck02.jpg", "5.99");
product_add_entry("Venture truck 03", array("All Products", "Venture", "Truck"), "img/truck/Venture_truck03.jpg", "5.99");

product_add_entry("Blackkross truck 00", array("All Products", "Blackkross", "Truck"), "img/truck/Blackkross_truck00.jpg", "7.99");

product_add_entry("Bustin weels 00", array("All Products", "Bustin", "Weels"), "img/weels/Bustin_weels00.jpg", "39.99");
product_add_entry("Bustin weels 01", array("All Products", "Bustin", "Weels"), "img/weels/Bustin_weels01.jpg", "35.99");
product_add_entry("Bustin weels 02", array("All Products", "Bustin", "Weels"), "img/weels/Bustin_weels02.jpg", "35.99");

product_add_entry("Kryptonics weels 00", array("All Products", "Kryptonics", "Weels"), "img/weels/Kryptonics_weels00.jpg", "29.99");
product_add_entry("Kryptonics weels 01", array("All Products", "Kryptonics", "Weels"), "img/weels/Kryptonics_weels01.jpg", "29.99");
product_add_entry("Kryptonics weels 02", array("All Products", "Kryptonics", "Weels"), "img/weels/Kryptonics_weels02.jpg", "29.99");

?>
