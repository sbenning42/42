<?PHP
function	is_admin($user)
{
	if (!file_exists("private/user"))
		return FALSE;
	if (!($table_user = unserialize_get_content("private/user")))
		return FALSE;
	return $table_user[$user]['right'];
}
?>
