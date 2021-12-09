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

<pre>


                                                                             POST KOMENNOT
                                                               
                                                               
LukitseKortti, POST     id=idKortti
                        {{Sovellusprojekti}}/asiakas/lukitus                               id

Avaa Kortti, POST       id=idKortti
                        {{Sovellusprojekti}}/asiakas/lukitusavaa                           id
  
Lukituksen tarkastus GET   
                        {{Sovellusprojekti}}/login/lukittu/5678
    
    
                                                                     

hae lisaa tapahtumia offsetilla  POST
                        {{Sovellusprojekti}}/tapahtumat/TapahtumaLisaa               idKortti, offset, Tila1

hae 5 viimeista saldotapahtumaa GET
                        {{Sovellusprojekti}}/tapahtumat/saldotapahtuma/5432/0

nayta lisaa tapahtumia GET
                        {{Sovellusprojekti}}/tapahtumat/TapahtumaLisaa     

Pane rahaa, POST
                        {{Sovellusprojekti}}/pano/panerahaa                          idKortti, summa, Tila1



nosta rahaa,       POST   
                        {{Sovellusprojekti}}/debitnosto/nostarahaa                   bodyyn idKortti, summa


 asiakkaan nimi    GET   
                        {{Sovellusprojekti}}/asiakas/5432      
 
 </pre>
