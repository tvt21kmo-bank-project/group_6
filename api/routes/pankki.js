const express = require('express');
const router = express.Router();
const pankki = require('../models/pankki_model');

router.get('/:id?/:Tila?',
 function(request, response) {
  if (request.params.id, request.params.Tila) {
    pankki.getById(request.params.id, request.params.Tila, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult[0].saldo);
      }
    });
  } else {
    pankki.getAll(function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  }
});

/*
router.post('/debitnosto', function(request, response) {
  pankki.nosta(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult.affectedRows);
    }
  });
});
/*

router.delete('/:id', 
function(request, response) {
  book.delete(request.params.id, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});


router.put('/:id', 
function(request, response) {
  book.update(request.params.id, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});*/

module.exports = router;
