<?php

function        strstra($h,$n)
{
  return array_shift(explode($n,$h,2));
}

function        has_negative($array)
{
  foreach ($array as $value)
    if ($value < 0)
      return true;
  return false;
}

function        make_table($array, $nb_var, $nb_contraintes)
{
  for ($i = 0; $i <= $nb_contraintes; $i++)
    $array[$i] = trim($array[$i]);
  for ($i = 0; $i <= $nb_contraintes; $i++)
    while (strstr($array[$i], "  ") != false)
      $array[$i] = str_replace("  ", " ", $array[$i]);

  $tableau = array();
  $max_coeffs = explode(" ", $array[0]);

  for ($j = 0; $j <= $nb_var+$nb_contraintes; $j++)
    $tableau[$nb_contraintes][$j] = ($j < $nb_var ? -$max_coeffs[$j] : 0);
  for ($i = 0; $i < $nb_contraintes; $i++){
    $contrainte = explode(" ", $array[$i+1]);

    if (count($contrainte) < $nb_contraintes){
      echo "Erreur : fichier incorrect.\n";
      exit(1);
    }

    for ($j = 0; $j < $nb_var+$nb_contraintes; $j++)
      $tableau[$i][$j] = ($j < $nb_var ? $contrainte[$j] : 0);

    $tableau[$i][$i+$nb_var] = 1;
    $tableau[$i][$nb_var+$nb_contraintes] = $contrainte[$nb_var];
    $tableau[$i][$nb_var+$nb_contraintes+1] = $i+$nb_var;
  }

  return $tableau;
}

function fact($n)
{
  return ($n < 2 ? (1) : ($n * fact($n - 1)));
}

function        simplex($tableau, $nb_var, $nb_contraintes, $iter, $iter_max)
{
  if ($iter < $iter_max)
    {
      $iter++;
      aff_table($tableau, $nb_var, $nb_contraintes);

      if (has_negative($tableau[$nb_contraintes])){
	$array = array_slice($tableau[$nb_contraintes], 0, $nb_contraintes+$nb_var);
	$var_entrante = array_search(min($array),$array);
	echo "Variable entrante : ".($var_entrante+1)."\n";
	$candidats = array();

	for ($i = 0; $i < $nb_contraintes; $i++)
	  if ($tableau[$i][$var_entrante] > 0)
	    $candidats[$i] = ($tableau[$i][$nb_var+$nb_contraintes])/($tableau[$i][$var_entrante]);

	$var_sortante = array_search(min($candidats),$candidats);
	echo "Variable sortante : ".($tableau[$var_sortante][$nb_var+$nb_contraintes+1]+1)."\n";
	$pivot = $tableau[$var_sortante][$var_entrante];

	if ($pivot == 0){
	  echo "Erreur. Fonction non bornee?\n";
	  exit(1);
	}

	for ($j = 0; $j <= $nb_var+$nb_contraintes; $j++)
	  $tableau[$var_sortante][$j] /= $pivot;

	for ($i = 0; $i <= $nb_contraintes; $i++){
	  if ($i != $var_sortante){
	    $pivot = $tableau[$i][$var_entrante];
	    for ($j = 0; $j <= $nb_var+$nb_contraintes; $j++)
	      $tableau[$i][$j] -= ($pivot)*($tableau[$var_sortante][$j]);
	  }
	}

	$tableau[$var_sortante][$nb_var+$nb_contraintes+1] = $var_entrante;
	simplex($tableau, $nb_var, $nb_contraintes, $iter, $iter_max);
      }

      else {
	echo "Solution\n";
	exit(0);
      }
    }
  echo "Function is not bounded, terminating algorithm\n";
  exit(1);
}
?>