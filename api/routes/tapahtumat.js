const { compare } = require('bcryptjs');
const { json } = require('express');
const express = require('express');
const router = express.Router();
const pankki = require('../models/tapahtumat_model');

router.get('/:id?',
 function(request, response) {
  if (request.params.id) {
    pankki.getById(request.params.id, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  }/* else {
    pankki.getAll(function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  }*/
});
router.get('/saldoTapahtuma/:id?', function(request, response) {
  if (request.params.id) {
    pankki.saldoTapahtuma(request.params.id, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  }
});
router.post('/tapahtumaLisaa', function(request, response){
  pankki.TapahtumaLisaa(request.body, function(err, dbResult){
      if(err){
          //response.json(err);
          //console.log("tapahtuma lisaa if");
          //response.json("Varat tapahtumaei riitä");
      }
      else{
        if (dbResult > 0)   
         {
          response.json(4);
          response.send(false);
          console.log("tassa");
        }
        else{
          console.log("tapahtuma lisaa else");
          //response.json(1);
        //console.log();
        response.json(dbResult[0]);}
        
      }
  })
}
);

module.exports = router;
