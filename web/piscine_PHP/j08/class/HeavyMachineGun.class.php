<?PHP

class				HeavyMachineGun extends Weapon
{
	public function	__construct()
	{
		$this->_name = "Heavy Machine Gun";
		$this->_charge = 0;
		$this->_shootType = 'standard';
		$this->_shootAera = array('near' => 3, 'middle' => 7, 'far' => 10);
		parent::__construct();
	}

	public function	who()
	{
		return __CLASS__;
	}	

	public function	getImpactAera($impactPos)
	{
		return array(array('x' => $impactPos['x'], 'y' => $impactPos['y']));
	}
}

?>
