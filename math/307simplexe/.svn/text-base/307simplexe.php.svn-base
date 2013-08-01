<?php
require "require/func.php";
require "require/func_aff.php";

function	main($argc, $argv)
{
  if ($argc == 2){
    if (file_exists($argv[1]) === false){
      echo "Cannot open file : $argv[1]\n";
      exit;
    }

    $handle = fopen($argv[1], 'r');

    if (filesize($argv[1])){
      if (!$handle){
	echo "Cannot open file : argv[1]\n";
	exit;
      }

      $buffer = fread($handle, filesize($argv[1]));
      $array = explode("\n", $buffer);
      fclose($handle);
    }
    echo "$argv[1]\n";

    foreach ($array as $line)
      echo $line."\n";

    $nb_var = count(explode(" ", $array[0]));
    $nb_contraintes = count($array)-2;
    $tableau = make_table($array, $nb_var, $nb_contraintes);
    $iter = 0;
    $iter_max = (fact($nb_var + $nb_contraintes) / (fact($nb_var) * fact($nb_contraintes)));
    simplex($tableau, $nb_var, $nb_contraintes, $iter, $iter_max);
  }

  else
    echo "No input file specified\n";
}

main($argc, $argv);
?>