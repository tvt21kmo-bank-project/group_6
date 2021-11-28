const express = require('express');
const router = express.Router();
const bank = require('../models/debitnosto_model');

router.post('/nostarahaa', function(request, response){
    bank.debit(request.body, function(err, dbResult){
        if(err){
            response.json(err);
        }
        else{
            response.json(dbResult.affectedRows);
        }
    })
}
);
/*
router.post('/credit_transfer', function(request, response){
    bank.credit(request.body, function(err, dbResult){
        if(err){
            response.json(err);
        }
        else{
            response.json(dbResult.affectedRows);
        }
    })
}
);
*/
module.exports = router;