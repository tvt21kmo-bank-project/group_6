const express = require('express');
const router = express.Router();
const bank = require('../models/debitnosto_model');

router.post('/nostarahaa', function(request, response){
    bank.debit(request.body, function(err, dbResult){
        if(err){
            response.json(err);
        }
        
        else{
            if(dbResult.affectedRows < 1 ){
            console.log("et saa");
            response.json("Varat ei riitä");
            }
            else{
            console.log("succes1");
            console.log(dbResult.affectedRows);
            response.json("Nosto onnistu!");
          


            }}
    }
    )
}
);

module.exports = router;