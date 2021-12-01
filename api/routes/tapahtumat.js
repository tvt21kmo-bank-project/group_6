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
});/*
router.post('/Tapahtumalisaa/:id?/:offset?',
 function(request, response) {
  if (request.params.id) {
    pankki.TapahtumaLisaa(request.params.id, request.params.offset, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  }
});*/
router.post('/TapahtumaLisaa', function(request, response){
  pankki.TapahtumaLisaa(request.body, function(err, dbResult){
      if(err){
          response.json(err);
      }
      else{
          response.json(dbResult);
      }
  })
}
);

module.exports = router;
