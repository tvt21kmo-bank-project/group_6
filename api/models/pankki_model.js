const db = require('../database');

const pankki = {
  getById: function(id, callback) {
    return db.query('select saldo from tili where idTili=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select saldo from tili', callback);
  },
 /* add: function(book, callback) {
    return db.query(
      'insert into book (name,author,isbn) values(?,?,?)',
      [book.name, book.author, book.isbn],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from book where id_book=?', [id], callback);
  },
  update: function(id, book, callback) {
    return db.query(
      'update book set name=?,author=?, isbn=? where id_book=?',
      [book.name, book.author, book.isbn, id],
      callback
    );
  }*/
};
module.exports = pankki;