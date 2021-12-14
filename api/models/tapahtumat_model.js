const db = require('../database');

const tapahtumat = {
  getById: function(id, callback) {
    return db.query('select idTilitapahtumat, aika, Tapahtuma, Maara from tilitapahtumat JOIN tili ON tilitapahtumat.Tili_idTili=tili.idTili join kortti on tili.idTili=kortti.tili_idTili where idKortti=? order by idTilitapahtumat desc', [id], callback);
},
  saldoTapahtuma: function(id, Tila, callback) {
  return db.query('select idTilitapahtumat, aika, Tapahtuma, Maara from tilitapahtumat JOIN tili ON tilitapahtumat.Tili_idTili=tili.idTili join kortti on tili.idTili=kortti.tili_idTili where idKortti=? AND Tila=? order by idTilitapahtumat desc limit 5', [id, Tila], callback);
  
  },

  TapahtumaLisaa: function(postData, callback) {
  return db.query('call lisaaTapahtumia(?,?,?)', [postData.idKortti, postData.offset, postData.Tila1], callback);

},
};
module.exports = tapahtumat; 