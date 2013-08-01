<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" dir="ltr">
<head>
    <meta http-equiv="content-type" content="text/html; charset=iso-8859-1" />
    <title>205 Inter</title>
	<center><h1><b>Mathematiques</b></h1></center>
	<center><h2><b>205 Inter</b></h2></center>
</head>
<body>
<center>
<br/><br/><br/>

<?php

function F($x){
  return exp(-($x*$x)/2);
  }

function simpson($N, $A, $B){
  $h = ($B - $A) / $N;
  $Iapp0 = F($A) + F($B);
  $Iapp1 = 0.0;
  $Iapp2 = 0.0;
  $NN = $N -1;
  for ($i=1; $i<=$NN; $i++){
    $X = $A + $i*$h;
    if (($i%2) == 0)
      $Iapp2 = $Iapp2 + F($X);
    else
      $Iapp1 = $Iapp1 + F($X);
  }
  return($Iapp = ($Iapp0 + 2.0 * $Iapp2 + 4.0 * $Iapp1) * $h / 3.0);
}

$fa = (1/(sqrt(2* M_PI))*simpson(20, -10, $_POST['A']));
$fb = (1/(sqrt(2* M_PI))*simpson(20, -10, $_POST['B']));
$res = $fb - $fa;
printf("P(%0.1f <= Z <= %0.1f) = %0.3f\n", $_POST['A'], $_POST['B'], $res);?>

<align="left">
<br/><br/><br/><a href="index.php">Retour</a>
</align>
</center>
</body>
</html>