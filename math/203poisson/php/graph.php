<?php // content="text/plain; charset=utf-8"
require_once ('src/jpgraph.php');
require_once ('src/jpgraph_scatter.php');

$datay = array($_GET['1'],$_GET['2'],$_GET['3'],$_GET['4'],$_GET['5'],$_GET['6'],$_GET['7']);
 
$graph = new Graph(500,300);
$graph->SetScale("textlin");
 
$graph->SetShadow();
$graph->img->SetMargin(40,40,40,40);        
 
$graph->title->Set("Loi Binomiale");
$graph->title->SetFont(FF_FONT1,FS_BOLD);

$sp1 = new ScatterPlot($datay);
$sp1->mark->SetType(MARK_CIRCLE);
$sp1->SetImpuls();
 
$graph->Add($sp1);
$graph->Stroke();
?>