<?PHP

class				ImperialCruiser extends Ship
{
	public function	__construct($owner)
	{
		$this->_name = "Sword Of Demolition";
		$this->_spriteSrc = "img/sprite/ImperialDestroyer.jpg";
		$this->_size['L'] = 7; // 7
		$this->_size['l'] = 3; // 3
		$this->_maneuvreInit = 5;
		$this->_speedInit = 16;
		$this->_PpInit = 15;
		$this->_PvInit = 10;
		$this->_PsInit = 0;
		$weapon = new HeavyMachineGun();
		$this->_weapons[] = $weapon;
		$this->_weapons[] = clone $weapon;
		parent::__construct($owner);
	}

	public function	who()
	{
		return __CLASS__;
	}

	public function	fire($target)
	{
		if ($target[0]->hearted(5) === TRUE) //	D6
			return TRUE;
	}
}

?>
