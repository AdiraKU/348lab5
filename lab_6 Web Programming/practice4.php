<html>
<body>
 <?php 
    $size = $_POST["size"]; 
    $row = 0;
    $col = 0;
    echo '<table>';
    while ($col<$size){
        echo '<tr>';
        while($row<$size){
            if ($row == 0 and $col == 0){
                echo '<th></th>';
            }elseif($row == 0 ){
                echo '<th>',$col,'</th>';
            }elseif($col == 0 ){
                echo '<th>',$row,'</th>';
            }else{
                echo '<th>',$row*$col,'</th>';
            }

            $row++;
        }
        $row=0;
        $col++;
        echo '</tr>';
    }
?>
</body>
</html>