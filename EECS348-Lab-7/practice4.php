<html lang="en-US">
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta charset="utf-8">
    <link href="style.css" rel="stylesheet" type="text/css">
    <title>Multiplication Table</title>
  </head>
  <body>
    <header>
      <hr>
      <nav role="navigation">
        <a href="index.html">Index</a>
      <hr>
    </header>
    <table>
    <?php
    for ($i = 1; $i <= (int)$_POST['size']; $i++) {
        echo "<tr>";
        for ($j = 1; $j <= (int)$_POST['size']; $j++) {
            echo "<td>" . ($i * $j) . "</td>";
        }
        echo "</tr>";
    }
    ?>
    </table>
  </body>
</html>
