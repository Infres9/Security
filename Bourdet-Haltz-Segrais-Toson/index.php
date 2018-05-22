<!doctype html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
</head>
<body>
<form action="index.php" method="post">
    <p>Votre pseudo : <input type="text" name="pseudo"/></p>
    <p>Votre commentaire : <textarea name="commentaire"></textarea></p>
    <p><input type="submit" value="OK"></p>
</form>
</body>
</html>


<?php
header('X-XSS-Protection:0');

$servername = "localhost";
$username = "root";
$password = "";
$dbname = "c9";

$conn = new mysqli($servername, $username, $password, $dbname);
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
} 

// prepare and bind
$stmt = $conn->prepare("INSERT INTO commentaires (pseudo, commentaire) VALUES (?, ?)");
$stmt->bind_param("ss", $pseudo, $commentaire);

$pseudo = $_POST['pseudo'];
$commentaire = $_POST['commentaire'];
$stmt->execute();

$sql = "SELECT pseudo, commentaire FROM commentaires";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
    echo "Liste des commentaires : <br>";
    while($row = $result->fetch_assoc()) {
        echo "Pseudo : " . $row["pseudo"]. "<br> Commentaire : " . $row["commentaire"]. "<br><br>";
    }
} else {
    echo "Aucun commentaire";
}
$conn->close();
?>

