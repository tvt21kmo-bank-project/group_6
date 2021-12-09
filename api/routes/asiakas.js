const express = require('express');
const router = express.Router();
const user = require('../models/asiakas_model');

router.get('/:id?',
 function(request, response) {
  if (request.params.id) {
    user.getById(request.params.id, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        //response.json(dbResult);
        response.json(dbResult[0].Nimi);
        //response.send(dbResult[0].nimi);
      }
    });
  } else {
    user.get(function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  }
});
router.post('/', 
function(request, response) {
  user.add(request.body, function(err, count) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body); 
    }
  });
});/*

router.delete('/:id', 
function(request, response) {
  user.delete(request.params.id, function(err, count) {
    if (err) {
      response.json(err);
    } else {
      response.json(count);
    }
  });
});
*/

router.put('/update', 
function(request, response) {
  user.update(request.params.id, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

router.post('/lukitus', function(request, response) {
  user.lukitus(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

router.post('/lukitusavaa', function(request, response) {
  user.lukitusavaa(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});


module.exports = router;