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
router.get('/saldoTapahtuma/:id?',
 function(request, response) {
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
          response.json(err);
          console.log("tapahtuma lisaa if");
          response.json("Varat tapahtumaei riitä");
      }
      else{
        console.log("tapahtuma lisaa else");
        console.log(dbResult.affectedRows);
        response.json(dbResult);
      }
  })
}
);

module.exports = router;
