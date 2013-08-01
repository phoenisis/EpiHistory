;******************************************************************************;
;                                                                              ;
;               cell.lsp for Game Of Life                                      ;
;               Created on : Tue Jul 10 11:35:50 2012                          ;
;               Made by : David "Thor" GIRON <thor@epitech.net>                ;
;                                                                              ;
;******************************************************************************;



;; A cell is the basic unit in the Game Of Life. A cell is in a certain state ;;
;; at a given time among "dead" and "alive". A cell is represented as a box   ;;
;; in the grid.

;; The rules to transit from a state to another are as follows :              ;;
;; - Dead   to dead   -> Exactly two alive neighbors                          ;;
;; - Dead   to alive  -> Exactly three alive neighbors                        ;;
;; - Alive  to alive  -> Exactly two alive neighbors                          ;;
;; - Alive  to dead   -> Less than two neighbors OR more than three neighbors ;;



(require 'grid "grid.lsp")

(provide 'cell)



(defconstant cell-dead-state   0) ; The "dead"   state
(defconstant cell-alive-state  1) ; The "alive"  state



(defun cell-set-to-alive-state (grid x y)
  "Sets the cell at coordinates x/y to the alive state."
  ;; Complete this function.
  (if (grid-valid-coords? grid x y) 
      (grid-set-at-coords grid x y cell-alive-state)
    )
)


(defun cell-set-to-dead-state (grid x y)
  "Sets the cell at coordinates x/y to the dead state."
  ;; Complete this function.
  (if (grid-valid-coords? grid x y) 
      (grid-set-at-coords grid x y cell-dead-state)
    )
  )


(defun cell-is-alive (grid x y)
  "Tests if a cell is alive."
  ;; Complete this function.
  (if (grid-valid-coords? grid x y) 
      (if (= (grid-get-at-coords grid x y) cell-alive-state)
	  t
	nil
	)
    )
)

(defun cell-count-alive-neighbors (grid x y)
  "Returns the number of alive neighbors of a cell at coordinates x/y."
  (defun test (grid list c)
    (if list
	(if (cell-is-alive grid (car (car list)) (car (cdar list)))
	    (test grid (cdr list) (+ 1 c))
	  (test grid (cdr list) c)
	  )
      c
      )
    )
  (test grid (grid-get-valid-neighbors grid x y) 0)
  )


(defun cell-transition (grid-f grid-t x y)
  "Transition from a state to another."
  ;; Complete this function.

  (if (cell-is-alive grid-f x y)
      (if ( or ( = (cell-count-alive-neighbors grid-f x y) 2) ( = (cell-count-alive-neighbors grid-f x y) 3))
	  (cell-set-to-alive-state grid-t x y)
	(cell-set-to-dead-state grid-t x y))
    (if ( = (cell-count-alive-neighbors grid-f x y) 3)
	(cell-set-to-alive-state grid-t x y)
      (cell-set-to-dead-state grid-t x y)
      )
    )
  )



(defun cell-to-string (cell)
  "Returns a string representation of the cell."
  (cond ((= cell-alive-state  cell) "X")
	((= cell-dead-state   cell) " ")
	(t                          "?")
	)
  )



;******************************************************************************;
 
