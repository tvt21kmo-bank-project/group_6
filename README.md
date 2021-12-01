# group_6

Ja lisäksi kansioon on luotava <b>.env</b> tiedosto, jonka sisältö on
<pre>
authUser='newAdmin'
authPass='newPass'

MYSQL = "mysql://netuser:netpass@localhost:3306/pankkiautomaatti"
</pre>

Kayttajatunnuksia databasessa alkaa olla 3 kkpl.
eli kirjautuminen tapahtuu seuraavilla tunnuksilla


<pre>
id              pin
5432            1234
5678            1234
5432            1234
</pre>

threadstack size 256k
