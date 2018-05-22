<?php
$servername = "localhost";
$username = "xx";
$password = "xx";
// Create connection
$id = $_POST['id'];

$mysqli = new mysqli($servername, $username, $password, $username);
/* Vérification de la connexion */
if ($mysqli->connect_errno) {
    printf("Échec de la connexion : %s\n", $mysqli->connect_error);
    exit();
}

/* Requête "Select" retourne un jeu de résultats */
if ($result = $mysqli->query("SELECT * FROM users WHERE id = $id")) {

    while($row = mysqli_fetch_assoc($result)){
        foreach ($row as $cname => $cvalue){
            print($cvalue);
            print("\t");
        }
        print("</br>");
    }

    $result->close();
}