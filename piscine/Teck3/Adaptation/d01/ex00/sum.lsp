(defun sum (nb)
  (defun sum_r (nb t)
    (if (> nb 0)
	(sum_r (- nb 1) (+ t 1))
      t
      )
    )
  (sum_r nb 0)
  )
