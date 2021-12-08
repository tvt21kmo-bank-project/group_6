const express = require('express');
const router = express.Router();
const bank = require('../models/pano_model');

router.post('/panerahaa', function(request, response){
    bank.debit(request.body, function(err, dbResult){
        if(err){
            response.json(err);
        }
        
        else{
            if(dbResult.affectedRows < 1 ){
            console.log("et saa");
            response.json("Luottoraha ylitetty");
            }
            else{
            console.log("succes1");
            console.log(dbResult.affectedRows);

            //response.json(dbResult.affectedRows);           

            response.json("Pano onnistu!");
          //response.json(dbResult.affectedRows);


            }}
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