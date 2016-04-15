<?PHP

class				ImperialDestroyer extends Ship
{
	public function	__construct($owner)
	{
		$this->_name = "Sword Of Absolution";
		$this->_spriteSrc = "img/sprite/ImperialDestroyer.jpg";
		$this->_size['L'] = 3;
		$this->_size['l'] = 1;
		$this->_maneuvreInit = 3;
		$this->_speedInit = 18;
		$this->_PpInit = 10;
		$this->_PvInit = 4;
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
