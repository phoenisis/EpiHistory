<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" dir="ltr">
<head>
    <meta http-equiv="content-type" content="text/html; charset=iso-8859-1" />
    <title>203 Poisson</title>
	<center><h1><b>Mathematiques</b></h1></center>
	<center><h2><b>203 Poisson</b></h2></center>
</head>
<body>
<center>
<br/><br/><br/>

<?php 
if(($_POST['1K'] AND $_POST['1N'] >= 0) AND $_POST['1N'] <= 100) 
{
	 if($_POST['1N'] > $_POST['1K'])
	 {
	 printf("%.0f\n", combi($_POST['1N'], $_POST['1K']));
	 }	
}
	else 
	{
	echo('Veuillez entrer une valeure de N et K comprise entre 0 et 100');
	}

function nfact($nbr)
{
		return $nbr > 1 ? $nbr * nfact($nbr -1):1;
}

function combi($n, $k)
{
	return (float)nfact($n)/(nfact($k)*(nfact($n -$k)));
}
?>
