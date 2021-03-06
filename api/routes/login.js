const express = require('express');
const router = express.Router();
const bcrypt = require('bcryptjs');
const login = require('../models/login_model');

router.post('/',   // tassa maaritellaan postimanin kaytto, mita komentoa postmanissa kaytetaan
  function(request, response) {
    if(request.body.username && request.body.password){
      const username = request.body.username;
      const password = request.body.password;
        login.checkPassword(username, function(dbError, dbResult) { // tarkastaaa databasesta salasanan
          if(dbError){
            response.json(dbError);
          }
          else{
            if (dbResult.length > 0) { // vertailee databasen salasanaa annettuun, paatos jatkosta true/false
              bcrypt.compare(password,dbResult[0].pin, function(err,compareResult) {
                if(compareResult) {
                  console.log("succes");
                  response.send(true);
                }
                else {
                    console.log("wrong password");
                    response.send(false);
                }			
              }
              );
            }
            else{
              console.log("user does not exists");
              response.send(false);
            }
          }
          }
        );
      }
    else{
      console.log("username or password missing");
      response.send(false);
    }
  }
);

router.get('/:idKortti?',
 function(request, response) {
  if (request.params.idKortti) {
    login.idKortti(request.params.idKortti, function(err, dbResult) {
      if(dbResult == ""){
        response.json(dbResult);
      } 
     else {
        response.json("0");
      }
    })}
 
  
});

router.get('/lukittu/:id?',
 function(request, response) {
  if (request.params.id) {
    login.getById(request.params.id, function(err, dbResult) {
      if (dbResult == "") {
        response.json(dbResult);
      } else {
        response.json(dbResult[0].Lukittu);
      }
    });
  
  }
});


module.exports=router;