<?php

function        aff_table($tableau, $nb_var, $nb_contraintes)
{
  $separator = "---------";

  for ($i = 0; $i <= $nb_var+$nb_contraintes; $i++)
    $separator .= "---------";

  echo "$separator\n";
  for ($i = 0; $i < $nb_contraintes; $i++){
    for ($j = 0; $j <= $nb_contraintes+$nb_var; $j++)
      printf(" %8.2f",$tableau[$i][$j]);
    printf(" %8.0f\n",$tableau[$i][$nb_contraintes+$nb_var+1]+1);
  }

  for ($j = 0; $j <= $nb_contraintes+$nb_var; $j++)
    printf(" %8.2f",$tableau[$nb_contraintes][$j]);

  echo "\n$separator\n";
  echo "f = ".(round(1000 * $tableau[$nb_contraintes][$nb_contraintes + $nb_var]) / 1000);
  echo "\n$separator\n";

  $vars = array_fill(0, $nb_var + $nb_contraintes, 0);
  for ($i = 0; $i < $nb_contraintes; $i++){
    $k = $tableau[$i][$nb_var + $nb_contraintes + 1];
    $vars[$k] = $tableau[$i][$nb_var + $nb_contraintes];
  }

  for ($i = 0; $i < $nb_var; $i++)
    printf("x".($i+1)." %8.2f\n", $vars[$i]);
  echo "$separator\n";
}

?>