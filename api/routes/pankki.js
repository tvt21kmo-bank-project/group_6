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


module.exports = router;
